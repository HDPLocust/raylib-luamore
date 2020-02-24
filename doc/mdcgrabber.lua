local function argparse(t)
	local conf = {}
	local i = 0
	while i < #arg do
		i = i + 1
		local v = arg[i]
		if v:find('^[\\-]') then
			i = i + 1
			local key = v:match('^[\\-]*(.*)')
			local t = conf[key] or {}
			table.insert(t, arg[i])
			conf[key] = t
		else
			table.insert(conf, v)
		end
	end
	return conf
end

local function check(v, msg)
	return v or (print(msg) and os.exit())
end

local function readfile(filename)

	local file, err = io.open(filename, 'rb')
	if not file then
		print( ("Can't read %s file: %s"):format(filename, err) )
		return nil, err
	end
	return file:read("*a"), file:close()
end

local conf = argparse(arg)

local files = check(conf.i and #conf.i > 0 and conf.i, "No input files specified")
local out   = (conf.o or {})[1] or "README.md"
print("Files to process: \n  " .. table.concat(files, ',\n  '))
print("Output file: \n  "      .. out)

local md_data = {}

print("Parsing")
for i, filename in ipairs(files) do
	print("  " .. filename)
	local data = readfile(filename)
	if data then
		for line in data:gmatch("/%*%s?![mM][dD](.-)%*/") do
			table.insert(md_data, line)
		end
	end
end

local text = table.concat(md_data, '\n')
out = check(io.open(out, 'wb'))
out:write(text)
out:close()
print("OK")