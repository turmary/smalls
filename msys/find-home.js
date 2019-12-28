#!/usr/bin/env cscript-wrap

var fso   = new ActiveXObject("Scripting.FileSystemObject");
var shell = new ActiveXObject("WScript.Shell");

function stdOut(s) {
	if (typeof WScript !== "undefined") {
		WScript.echo(s);
	} else if (typeof navigator !== "undefined") {
		document.write(s + "<br>");
	}
}

function showDriveType(drv) {
	var d = fso.GetDrive(drv)
	var t

	switch (d.DriveType) {
	case 1: t = "Removable"; break;
	case 2: t = "Fixed"; break;
	case 3: t = "Network"; break;
	case 4: t = "CD-ROM"; break;
	case 5: t = "RAMDisk"; break;
	default:t = "Unkown"; break;
	}
	return t;
}

function findHome() {
	var e, home = "";

	e = new Enumerator(fso.Drives);
	for (; !e.atEnd(); e.moveNext()) {
		var drv = e.item();

		if (!drv.IsReady || showDriveType(drv) != "Fixed") {
			continue;
		}

		var path = fso.BuildPath(drv.Path, "\\home");
		if (!fso.FolderExists(path)) {
			continue;
		}

		var WshSysEnv = shell.Environment("USER")
		var upath = path + "\\" + WshSysEnv("USERNAME")
		if (fso.FolderExists(upath)) {
			/*
			home = "/" + drv.DriveLetter.toLowerCase() + "/home";
			*/
			var re = /\\/g;
			home = path.replace(re, '/');
		}
	}
	return home;
}

function main() {
	stdOut(findHome())
	/*
	var stdin = WScript.StdIn;
	var str = stdin.ReadLine();
	*/
	return;
}

main()
