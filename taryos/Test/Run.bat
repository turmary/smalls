SET BXSHARE=C:\TaryInst\Bochs-2.1
PUSHD ".\"
IF NOT EXIST A:\NUL (
	"F:\TaryInst\vfd21\vfdwin.exe" /open A: TARYOS.IMG /Q
)
IF NOT "%1" == "NORUN" %BXSHARE%\bochs -q -f bochsrc.bxrc
POPD

