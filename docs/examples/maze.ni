note The program, drawing a maze (ported from BASIC).

	define START_LABEL as "start"
	define SLASH       as "/"
	define BACKSLASH   as "\\"

label start
	let factor = Random(0, 1)
	if factor > 0.5 then
		ShowString(SLASH)
	end
	if factor < 0.5 or factor = 0.5 then
		ShowString(BACKSLASH)
	end
	go to START_LABEL
