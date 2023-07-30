'*************************main*****************************
10 REM Lunar Lander
20 REM By diomidis Spinellis
30 PRINT "You are on the Lunar Lander about to leave the spacecraft."
60 GOSUB 4000
70 GOSUB 1000
80 GOSUB 2000
90 GOSUB 3000
100 H = H - V           'H---Height     V---Velocity
110 V = ((V + G) * 10 - U * 2) / 10     'F---Fuel       U---Use Fuel    G---g
120 F = F - U
130 IF H > 0 THEN GOTO 80
135 H = 0
140 GOSUB 2000
150 IF V > 5 THEN GOTO 200
160 PRINT "Congratulations! This was a very good landing."
170 GOSUB 5000
180 GOSUB 10
200 PRINT "You have crashed."
210 GOTO 170    'IF don't use this statement, it will appear stack overflow

'*************************init data************************
1000 REM Initialise
1010 V = 70
1020 F = 500
1030 H = 1000
1040 G = 2
1050 RETURN

'*************************print****************************
2000 REM Print values
2010 PRINT "Meter readings"
2015 PRINT "------------------"
2020 PRINT "Fuel (gal):"
2030 PRINT F
'2035 IF H <> 0 THEN GOSUB 2200 ELSE GOSUB 2100
2035 IF H = 0 THEN GOSUB 2100
2040 GOSUB 2200
2050 PRINT V
2060 PRINT "Height (m):"
2070 PRINT H
2080 RETURN

2100 PRINT "Landing velocity (m/sec):"
2110 RETURN
2200 PRINT "Velocity (m/sec):"
2210 RETURN

'*************************input****************************
3000 REM User input
3005 IF F = 0 THEN GOTO 3070
3010 PRINT "How much fuel will you use?"
3020 INPUT U
3025 IF U < 0 THEN GOTO 3090
3030 IF U < F THEN GOTO 3060
3035 IF U = F THEN GOTO 3060
3040 PRINT "Sorry, you have not got that much fuel!"'":  "
3050 GOTO 3010
3060 RETURN

3070 U = 0
3080 RETURN

3090 PRINT "No cheating please! Fuel must be >= 0."
3100 GOTO 3010

'*************************begin****************************
4000 REM Detachment
4005 PRINT "Ready for detachment"
4007 PRINT "---- COUNTDOWN ----"
4010 FOR I = 1 TO 11
4020 PRINT 11 - I :GOSUB 4500
'4025 GOSUB 4500
4030 NEXT 'I
4035 PRINT "You have left the spacecraft."
4037 PRINT "Try to land with velocity less than 5 m/sec."
4040 RETURN

4500 REM delay
4510 FOR J = 1 TO 10
4513 FOR S = 1 TO J
4516 NEXT 'S
4520 NEXT 'J
4530 RETURN

'*************************exit*****************************
5000 PRINT "Do you want to play again? (0 = no, 1 = yes)"
5010 INPUT y
5020 IF y = 0 THEN GOTO 5040
5030 RETURN
5040 PRINT "Have a nice day."