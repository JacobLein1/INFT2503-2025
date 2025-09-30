#include <algorithm>
#include <gtkmm.h>
#include <iostream>
#include <vector>

using namespace std;

void oppgave1() {
  vector<double> numbers = {1.1, 2.0, 4.0, 5.4, 9.0};
  cout << "First number:" << numbers.front() << endl;
  cout << "Last number:" << numbers.back() << endl;

  numbers.emplace(numbers.begin() + 1, 2.4);
  cout << "First number after emplace:" << numbers.front() << endl;

  auto iterator = std::find(numbers.begin(), numbers.end(), 5.4);

  if (iterator != std::end(numbers)) {
    cout << "Fant søkt verdi: " << *iterator << endl;
  }
}

void oppgave2() {
}

class Window : public Gtk::Window {

public:
  Gtk::Box box;
  Gtk::Entry entry1;
  Gtk::Entry entry2;
  Gtk::Button button;
  Gtk::Label label;

  void on_entries_changed() {
    if (!entry1.get_text().empty() && !entry2.get_text().empty())
      button.set_sensitive(true);
    else
      button.set_sensitive(false);
  }

  Window() : box(Gtk::ORIENTATION_VERTICAL) {
    set_title("Oving4");

    button.set_label("Combine names");

    box.pack_start(entry1); // Add the widget entry to box
    box.pack_start(entry2);
    box.pack_start(button); // Add the widget button to box
    box.pack_start(label);  // Add the widget label to box

    add(box);            // Add vbox to window
    show_all_children(); // Show all widgets
    button.set_sensitive(false);

    entry1.signal_changed().connect(sigc::mem_fun(*this, &Window::on_entries_changed));
    entry2.signal_changed().connect(sigc::mem_fun(*this, &Window::on_entries_changed));

    /*entry1.signal_activate().connect([this]() {
      label.set_text("Entry activated");
    });

    entry2.signal_activate().connect([this]() {
      label.set_text("Entry activated");
    });*/

    button.signal_clicked().connect([this]() {
      label.set_text("Names combined: " + entry1.get_text() + " " + entry2.get_text());
      // Add combine name function
    });
  }
};

int main() {
  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}
