import std.stdio;
import gtk.MainWindow;
// import gtk.Label;
import gtk.Main;
import gtk.Builder;
import gtk.Window;
import gtk.CssProvider;
import gtk.Widget;
import gtk.Button;
import gtk.StyleContext;
import gdk.Screen;

void main(string[] args)
{
	Main.init(args);

	Builder builder = new Builder();
	builder.addFromFile("./source/ui/test.glade");
	builder.connectSignals(null);

	CssProvider css = new CssProvider();
	css.loadFromPath("./source/ui/main.css");
	Screen screen = Screen.getDefault();
	StyleContext.addProviderForScreen(screen, css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	Window win = cast(Window) builder.getObject("MainWindow");


	// StyleContext winStyleContext = win.getStyleContext();
	// winStyleContext.addProvider(css, 500);

	// Button btn = cast(Button) builder.getObject("ButtonQuit");
	// StyleContext btnStyleContext = btn.getStyleContext();
	// btnStyleContext.addProvider(css, 500);

	win.showAll();
	// MainWindow win = new MainWindow("hello world");
	// win.setOpacity(0.2);
	// win.setDefaultSize(200,200);
	// win.add(new Label("hello label"));

	Main.run();
}

extern(C) void on_destroy_main_window() {
	writeln("destroying");

	Main.quit();
}

extern(C) void on_button_clicked() {
	writeln("click");
	Main.quit();
}