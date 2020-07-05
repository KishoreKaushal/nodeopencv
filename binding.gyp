{
    "targets" : [
        {
            "target_name" : "addon",
            "cflags" : ["`pkg-config --cflags opencv4`", '-std=c++11'],
            "link_settings" : {
                "libraries" : ["`pkg-config --libs opencv4`"]
            },
            "sources" : ["addon.cc"]
        }
    ]
}