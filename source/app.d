import std.stdio;
import gtk.MainWindow;
// import gtk.Label;
import gtk.Main;
import gtk.Builder;
import gtk.Window;
import gtk.CssProvider;
import gtk.Widget;
import gtk.StyleContext;

void main(string[] args)
{
	Main.init(args);

	Builder builder = new Builder();
	builder.addFromFile("./source/ui/main.glade");
	builder.connectSignals(null);
	Window win = cast(Window) builder.getObject("MainWindow");

	CssProvider css = new CssProvider();
	css.loadFromPath("./source/ui/main.css");

	StyleContext winStyleContext = win.getStyleContext();
	winStyleContext.addProvider(css, 0);

	win.showAll();
	// MainWindow win = new MainWindow("hello world");
	// win.setOpacity(0.2);
	// win.setDefaultSize(200,200);
	// win.add(new Label("hello label"));
	// win.showAll();
	Main.run();
}

extern(C) void on_destroy_main_window() {
	writeln("destroying");

	Main.quit();
}

extern(C) void on_button_clicked() {
	writeln("click");
}