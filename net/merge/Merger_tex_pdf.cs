using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void tex_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.tex";
            var pathSource2 = @"..\..\TestData\Second\test.tex";

            var firstDoc = new Document(pathSource1,
                new TeXLoadOptions
                { 
                    NoLigatures = false,
                    RasterizeFormulas = true,
                    ShowTerminalOutput = true
                });

            var secondDoc = new Document(pathSource2,
                new TeXLoadOptions
                { 
                    NoLigatures = false,
                    RasterizeFormulas = true,
                    ShowTerminalOutput = true
                });

            var outputDoc = new Document();
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            outputDoc.Save("test.pdf", SaveFormat.Pdf);
        }
    }
}
