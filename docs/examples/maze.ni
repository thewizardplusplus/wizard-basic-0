note The program, drawing a maze (ported from BASIC).

	define SLASH       as "/"
	define BACKSLASH   as "\\"

label start
	let factor = Rand()
	if factor > 0.5 then
		ShowString(SLASH)
	end
	if factor < 0.5 or factor = 0.5 then
		ShowString(BACKSLASH)
	end
	go to start
