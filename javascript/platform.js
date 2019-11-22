
function GetScriptEngineInfo(){
	var s;

	s = ""; // 根据必要的信息创建字符串。
	s += ScriptEngine() + " Version ";
	s += ScriptEngineMajorVersion() + ".";
	s += ScriptEngineMinorVersion() + ".";
	s += ScriptEngineBuildVersion();
	return s;
}

function GetBrowserInfo() {
	var s;

	s = "";
	s += "<p>浏览器代号 : " + navigator.appCodeName    + "</p>";
	s += "<p>浏览器名称 : " + navigator.appName        + "</p>";
	s += "<p>浏览器版本 : " + navigator.appVersion     + "</p>";
	s += "<p>启用Cookies: " + navigator.cookieEnabled  + "</p>";
	s += "<p>硬件平台   : " + navigator.platform       + "</p>";
	s += "<p>用户代理   : " + navigator.userAgent      + "</p>";
	s += "<p>代理语言   : " + navigator.systemLanguage + "</p>";
	return s;
}

function stdOut(s) {
	if (typeof WScript !== "undefined") {
		WScript.echo(s);
	} else if (typeof navigator !== "undefined") {
		document.write(s);
	} else {
	
	}
}

var inf;
if (typeof WScript !== "undefined") {
	inf = GetScriptEngineInfo();
} else if (typeof navigator !== "undefined") {
	inf = GetBrowserInfo();
}

if (inf != null) {
	stdOut(inf);
}
