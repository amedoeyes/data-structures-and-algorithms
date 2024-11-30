set_languages("c++23")
set_warnings("allextra", "pedantic", "error")

add_rules("mode.debug", "mode.release", "mode.releasedbg", "mode.check", "mode.profile")
add_rules("plugin.compile_commands.autoupdate", { lsp = "clangd", outputdir = "build" })

target("dsa", function()
	set_kind("static")
	add_includedirs("include", { public = true })
end)

for _, file in ipairs(os.files("tests/**.cpp")) do
	target(path.basename(file), { files = file, deps = "dsa" })
end
