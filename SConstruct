# SConstruct
env = Environment(tools = ["default", "textfile"])
from config_cache import USRPREFIX, LISTPRICE_CC, STRIP_LISTPRICE

# set default compile flags for gcc
env.Append(CCFLAGS = ["-Wall", "-Wextra", "-O2"])

# set user defined compiler if specified
if (LISTPRICE_CC != "DEFAULT"):
	env['CC'] = LISTPRICE_CC

AddOption('--verbose',
	dest="verbose",
	default=False,
	action="store_true",
	help="Provide verbose output")
AddOption('--install',
	dest='install',
	action='store_true',
	help='Install the software',
	default=False)
AddOption('--uninstall',
	dest='uninstall',
	action='store_true',
	help='Uninstall the software',
	default=False)

# activate extra output with scons --verbose=true
if env.GetOption('verbose'):
	Progress('Evaluating $TARGET\n')

# compile listprice
csl = env.Program(["src/listprice.c"])

# strip listprice binary to reduce size unless otherwise instructed
if (STRIP_LISTPRICE == 1):
	env.Command("src/listprice_tmp", "src/listprice", "strip src/listprice")

if env.GetOption('uninstall'):
	env.SetOption('clean', 1)
if (env.GetOption('install')) or (env.GetOption('uninstall')):
	Default(env.Install(USRPREFIX + '/bin', csl))
