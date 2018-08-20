
-- config = {
--     title = "config lua"
--     width = 800
--     height = 600
-- }
str = "I am so cool"
tbl = {name = "shun", id = 123}

config = function (arg)
	print("logging")
	print(arg)
	local title = "draw lua"
	local width = 800
	local height = 600
	return title, width, height
end

drawLine()

CreateButton(25, 35, 100, 30)
CreateButton(35, 85, 200, 30)
CreateButton(65, 155, 50, 50)
