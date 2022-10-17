# https://gbegerow.wordpress.com/2012/04/09/interprocess-communication-in-powershell/

$pipe = New-Object System.IO.Pipes.NamedPipeClientStream("\\.\pipe\Wulf");
$pipe.Connect();

$sw = New-Object System.IO.StreamWriter($pipe);
$sw.WriteLine("Go");
$sw.WriteLine("start from System.IO.StreamWriter($pipe)");
$sw.WriteLine('exit');

$sw.Dispose();
$pipe.Dispose();
