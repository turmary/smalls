#!/TaryInstalled/WinAVR/bin/wish84.exe
################################################
#
#	this is tary the first tcl script
#
################################################

# this program conver the Fahr to Celsius

proc main {} {
	set lower 0;
	set upper 300;
	set step  20;

	puts "Fahr    Celsius\n";
	set fahr $lower;
	while {$fahr <= $upper} {
		set celsius [expr (5.0 / 9.0) * ($fahr - 32.0)];
		set strout "[format %3.0f $fahr]     ";
		append strout "[format %6.1f $celsius]";
		puts $strout;
		set fahr [expr $fahr + $step];
	}
}

main;

