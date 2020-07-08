#include "app.hpp"
// #include "../3rdparty/CLI11.hpp"

int main(int argc, char **argv)
{
    lock::App app{};
    return app.parse(argc, argv);
    // CLI::App app{"App description"};

    // bool version {};

    // std::string filename = "default";
    // app.add_option("-f,--file", filename, "A help string");
    // app.add_flag_callback("--dupa", [](){ std::cout << "dupa callback\n"; });
    // app.add_flag_callback("--version", [&version]{ version = true; });
    // auto sub = app.add_subcommand("sub", "sub description");
    // sub->add_flag_callback("--chuj", []{ std::cout << "No i chuj\n"; });
    // // sub->callback([&sub]{ if (sub->count_all() <= 1) throw CLI::CallForHelp(); });

    // app.callback([&app]{ if (app.count_all() <= 1) throw CLI::CallForHelp(); });

    // try 
    // { 
    //     (app).parse((argc), (argv)); 
    // }
    // catch(const CLI::ParseError &e) 
    // {
    //     return (app).exit(e); 
    // }

    // if (version)
    // {
    //     std::cout << "1.0.0\n";
    // }

    // return 0;
}
