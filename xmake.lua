set_languages("c++23")
set_toolchains("clang")
set_runtimes("c++_shared")
set_policy("build.c++.modules", true)
set_warnings("allextra", "pedantic", "error")

add_rules("mode.debug", "mode.release", "mode.check")
add_rules("plugin.compile_commands.autoupdate", { lsp = "clangd", outputdir = "build" })

target("dsa", function()
	set_kind("static")
	add_files("./src/**.cppm", { public = true })
end)

for _, file in ipairs(os.files("tests/**.cpp")) do
	target(path.basename(file), { files = file, deps = "dsa" })
end
