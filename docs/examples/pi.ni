note The program, calculated the number pi (by the Gauss–Legendre algorithm).

	define LOOP_LABEL as "loop"
	define MESSAGE    as "Pi = "
	define DOT        as "."
	define NEW_LINE   as "\n"
	let ERROR = 0.000001

	let a = 1
	let b = 1 / SquareRoot(2)
	let t = 1 / 4
	let p = 1

label loop
	let new_a = (a + b) / 2
	let new_b = SquareRoot(a * b)
	let new_t = t - p * (a - new_a) * (a - new_a)
	let new_p = 2 * p
	if Modulus(a - b) > ERROR then
		go to LOOP_LABEL
	end

	let pi = (a + b) * (a + b) / (4 * t)
	ShowString(MESSAGE)
	ShowNumber(pi)
	ShowString(DOT)
	ShowString(NEW_LINE)
