-- config = {}
--
-- -- 程序可以用 config.lua 来配置窗口标题 宽 高这 3 个选项
-- -- 定义一个常量
-- config.title = "draw lua"
-- config.width = 800
-- config.height = 600

drawLine()

config = function ()
	print("logging")
	local title = "draw lua"
	local width = 800
	local height = 600
	return title, width, height
end


return config
