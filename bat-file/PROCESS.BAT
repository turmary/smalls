IF EXIST "G:\CEXAM.DOC" DEL "G:\CEXAM.DOC"
ECHO �ƶ���Cϰ�� >G:\CEXAM.DOC
FOR %%i in (T??.C) DO (
	rem echo -------------------- >>G:\CEXAM.DOC
	echo /*%%i*/ >>G:\CEXAM.DOC
	copy G:\CEXAM.DOC+%%i G:\CEXAM.DOC
	echo /*%%i End*/ >>G:\CEXAM.DOC
	echo -------------------- >>G:\CEXAM.DOC
)