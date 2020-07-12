#include "workspace.h"

files::files() : fontSize(12), nowFontSize(12), prevIndex(0) { }
files * getFile = new files();
files::~files() { delete getFile; }

theme::theme() { }
theme * getTheme = new theme();
theme::~theme()  { delete getTheme; }
