namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void tex_to_pdf()
        {
            const string pathSource1 = "../../TestData/test.tex";
            const string pathSource2 = "../../TestData/Second/test.tex";

            //TeX files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1,
                new Aspose.Pdf.TeXLoadOptions
                {
                    //Cancels ligatures in all fonts
                    NoLigatures = false,
                    //Rasterize scientific formulas to images 
                    RasterizeFormulas = true,
                    //Print parsing steps details to console output
                    ShowTerminalOutput = true
                });

            var secondDoc = new Aspose.Pdf.Document(pathSource2,
                new Aspose.Pdf.TeXLoadOptions
                {
                    //Set ligatures in all fonts
                    NoLigatures = false,
                    //Rasterize scientific formulas to images 
                    RasterizeFormulas = true,
                    //Print parsing steps details to console output
                    ShowTerminalOutput = true
                });

            var outputDoc = new Aspose.Pdf.Document
            {
                //set less memory usage with unload instead of fast performance
                EnableObjectUnload = true
            };

            foreach (var page in firstDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            //save result pdf to file
            outputDoc.Save("Merger_tex_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
