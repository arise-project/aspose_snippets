using System;
using System.Collections.Generic;

namespace snippet_validator
{
    class Program
    {
        static void Main(string[] args)
        {
        	Dictionary<string, string []> runnerOpts = new Dictionary<string, string []> {
				{"merger_cpp", new string [] { "../cpp/merge/bin/debug/merge.exe" } },
				{"split_cpp", new string [] { "../cpp/split/bin/debug/split.exe" } },
				{"watermark_cpp", new string [] { "../cpp/watermark/bin/debug/watermark.exe" } },

				{"merger_java", new string [] { "java", "-jar", "../java/merge/target/merge.jar" } },
				{"split_java", new string [] { "java", "-jar", "../java/split/target/split.jar" } },
				{"watermark_java", new string [] { "java", "-jar", "../java/watermark/target/watermark.jar" } },

				{"merger_net", new string [] { "dotnet", "../net/merge/bin/debug/merge.dll" } },
				{"split_net", new string [] { "dotnet", "../net/split/bin/debug/split.dll" } },
				{"watermark_net", new string [] { "dotnet", "../net/watermark/bin/debug/watermark.dll" } },

				{"merger_python", new string [] { "python3", "../python/merge/main.py" } },
				{"split_python", new string [] { "python3", "../python/split/main.py" } },
				{"watermark_python", new string [] { "python3", "../python/watermark/main.py" } },
			};
        	
        	string [] outputExts = new string [] 
        	{
        		"pdf",
        		"docx",
        		"bmp",
        		"doc",
        		"epub",
        		"html",
        		"jpg",
        		"png",
        		"pptx",
        		"svg",
        		"tex",
        		"txt",
        		"tiff",
        		"xls",
        		"xps"
        	};
        	
        	foreach(var opt in runnerOpts)
        	{
        		
        	}
        	
            Console.WriteLine("Hello World!");
        }
    }
}
