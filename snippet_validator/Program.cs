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
        		var args = new Dictionary<string, string> {
				{ "-p", "title"},
				{ "-l", "games"},
				...
				};

				var arguments = string.Join(" ", args.Select((k) => string.Format("{0} {1}", k.Key, "\"" + k.Value + "\"")));

				var dllPath = @"C:\Users\xyz\Documents\Visual Studio 2017\myConsole\bin\Debug\netcoreapp2.1\myConsole.dll";
				ProcessStartInfo procStartInfo = new ProcessStartInfo();
				procStartInfo.FileName = "C:\....\cmd.exe";
				procStartInfo.Arguments = $"dotnet \"{dllPath}\" {arguments}";
				procStartInfo.UseShellExecute = false;
				procStartInfo.CreateNoWindow = false;
				procStartInfo.RedirectStandardOutput = true;
				procStartInfo.RedirectStandardError = true;

				StringBuilder sb = new StringBuilder();
				Process pr = new Process();
				pr.StartInfo = procStartInfo;

				pr.OutputDataReceived += (s, ev) =>
				{
					if (string.IsNullOrWhiteSpace(ev.Data))
					{
						return;
					}

					string[] split = ev.Data.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
					int.TryParse(split[split.Length - 1], out output);
				};

				pr.ErrorDataReceived += (s, err) =>
				{
					// do stuff here
				};

				pr.EnableRaisingEvents = true;
				pr.Start();
				pr.BeginOutputReadLine();
				pr.BeginErrorReadLine();

				pr.WaitForExit();
        	}
        	
            Console.WriteLine("Hello World!");
        }
    }
}
