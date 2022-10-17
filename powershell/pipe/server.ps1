#https://gbegerow.wordpress.com/2012/04/09/interprocess-communication-in-powershell/

$pipe=New-Object System.IO.Pipes.NamedPipeServerStream("\\.\pipe\Wulf");
'Created server side of "\\.\pipe\Wulf"'
$pipe.WaitForConnection();

$sr = New-Object System.IO.StreamReader($pipe);
While (($cmd = $sr.ReadLine()) -ne 'exit')
{
  $cmd
};

$sr.Dispose();
$pipe.Dispose();
