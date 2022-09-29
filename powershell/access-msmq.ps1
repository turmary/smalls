# from https://stackoverflow.com/questions/765954/setting-permissions-on-a-msmq-queue-in-a-script
# or https://www.dotblogs.com.tw/stanley14/2016/09/27/001310

Write-Host ""
Write-Host "Examples using the .NET System.Messaging assembly to access MSMQ"
Write-Host ""

Write-Host "... load the .NET Messaging assembly"
[Reflection.Assembly]::LoadWithPartialName("System.Messaging")

Write-Host ""

if ([System.Messaging.MessageQueue]::Exists(".\private$\MyQueue"))
  {
  [System.Messaging.MessageQueue]::Delete(".\private$\MyQueue")
  Write-Host "... delete old myqueue"
  }
if ([System.Messaging.MessageQueue]::Exists(".\private$\BtsQueue"))
  {
  [System.Messaging.MessageQueue]::Delete(".\private$\BtsQueue")
  Write-Host "... delete old btsqueue"
  }

Write-Host "... create a new queue"
$q1 = [System.Messaging.MessageQueue]::Create(".\private$\MyQueue")

Write-Host "... create new queue, set FullControl permissions for TARY-THINK\TARY"
$qb = [System.Messaging.MessageQueue]::Create(".\private$\BtsQueue")

$qb.SetPermissions("TARY-THINK\TARY",
      [System.Messaging.MessageQueueAccessRights]::FullControl,
      [System.Messaging.AccessControlEntryType]::Set)

Write-Host "... list existing queues"
$pqs = [System.Messaging.MessageQueue]::GetPrivateQueuesByMachine(".")
Write-Host "    Count: "$pqs.length  -ForegroundColor gray
foreach($q in $pqs)
  {
    Write-Host "       "$q.QueueName  -ForegroundColor gray
  }

Write-Host "... access existing queue"
$q2 = New-Object System.Messaging.MessageQueue ".\private$\MyQueue"

Write-Host "... adding string Formatter and additional properties "
$q2.Formatter.TargetTypeNames = ,"System.String"
$q2.MessageReadPropertyFilter.ArrivedTime = $true
$q2.MessageReadPropertyFilter.SentTime = $true

Write-Host "... create a new High priorty message "
$msg = New-Object System.Messaging.Message "TestMessage"
$msg.label = "Test Msg Label"
$msg.body = "Add some body to test message"
$msg.priority = [System.Messaging.MessagePriority]::High

Write-Host "... send the High message"
$q2.send($msg)

$msg.body = "Some more text for the test message"
$msg.priority = [System.Messaging.MessagePriority]::Low

Write-Host "... send the Low message"
$q2.send($msg)

Write-Host "... check the queue "
Write-Host "    Count: "$q2.GetAllMessages().length  -ForegroundColor gray

Write-Host "... peek at queue"
$ts = New-Object TimeSpan 10000000 # 1 sec. timeout just in case MSMQ is empty
$pk = $q2.Peek($ts)
Write-Host "    ArrivedTime: "$pk.ArrivedTime.DateTime -ForegroundColor gray
Write-Host "    SentTime   : "$pk.SentTime.DateTime -ForegroundColor gray

Write-Host "... check the queue "
Write-Host "    Count: "$q2.GetAllMessages().length -ForegroundColor gray

Write-Host "... receive from queue"
$rmsg = $q2.receive($ts)
Write-Host "    Body : "$rmsg.body  -ForegroundColor gray
Write-Host "    Label: "$rmsg.label -ForegroundColor gray

Write-Host "... check the queue "
Write-Host "    Count: "$q2.GetAllMessages().length  -ForegroundColor gray

Write-Host "... purge the queue "
$q2.Purge()

Write-Host "... check the queue "
Write-Host "    Count: "$q2.GetAllMessages().length  -ForegroundColor gray

Write-Host ""
Write-Host "All done, but remember to delete the test queues !!"
