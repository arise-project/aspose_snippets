```cs

//1. SVG files can be parsed and loaded as Aspose Document
//Adust pdf page size to svg size
firstDoc = new Aspose.Pdf.Document("1.svg", new Aspose.Pdf.SvgLoadOptions { AdjustPageSize = true});
secondDoc = new Aspose.Pdf.Document("2.svg", new Aspose.Pdf.SvgLoadOptions { AdjustPageSize = false });

//2. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_svg_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
```