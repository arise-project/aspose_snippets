```cs

outputDoc = new Aspose.Pdf.Document();

//TeX files can be parsed and loaded as Aspose Document
//Cancels ligatures in all fonts
//Rasterize scientific formulas to images 
//Print parsing steps details to console output
opt1 = new Aspose.Pdf.TeXLoadOptions
{
    NoLigatures = false,
    RasterizeFormulas = true,
    ShowTerminalOutput = true
};
firstDoc = new Aspose.Pdf.Document("1.tex",opt1);
secondDoc = new Aspose.Pdf.Document("2.tex",opt1);

//add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//save result pdf to file
outputDoc.Save("Merger_tex_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
```