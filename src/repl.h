/**
 * REPL.
 * Read-Elaborate-Process Loop. This class realises the REPL functionality within PhantomJS.
 * It uses a QSocketNotifier to listed on the STDIN and act upon user input.
 *
 * It receives at creation:
 * - Destination QWebFrame that will "evaluate()" User Input
 * - User type error handling
 * - Console Coloring (maybe)
 *
 * On creation it will create a QSocketNotifier, and attach it in READ to the STDIN.
 * In this way the class Phantom can delegate this functionality completely.
 *
 * NOTES:
 * - I need to analyse what to do with STDOUT/STDERR
 * - Coloring of the OUTPUT must be CROSS PLATFORM code (shouldn't do it on Windows or TTY not enabled for color)
 */