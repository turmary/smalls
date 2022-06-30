param (
    [long] $begin = 2,
    [long] $count = 18
)

$TestPrime = {
    param (
        [long] $x
    )
    $root = [System.Math]::Sqrt($x)
    for ($i = 2; $i -le $root; ++$i) {
        if ($x % $i -eq 0) {
            Return $false
        }
    }
    Return $true
}

# Test-Prime 8
$Primes = @{}
$PrimeMutex = [System.Threading.Mutex]::new()
# [System.Threading.Mutex] | Get-Member -Static -MemberType Methods

$AddPrime = {
    param (
        [long] $v
    )
    $Primes.add($v, 1)
    # Write-Output $v
}

$begin..($begin + $count - 1) | ForEach { Start-ThreadJob {
    # $r = Get-Random -Maximum 1000;
    # sleep -milliseconds $r;
    $p = ($Using:TestPrime).Invoke($Using:_)
    if ($p) {
        # $Using:Primes += $Using:_
        $null = ($Using:PrimeMutex).WaitOne()
        ($Using:AddPrime).Invoke($Using:_)
        ($Using:PrimeMutex).ReleaseMutex()
    }
} } | Receive-Job -Wait

$PrimeMutex.Dispose()
Remove-Job -State Completed
$Primes.Keys | Sort # | ForEach { Write-Output $_ }
