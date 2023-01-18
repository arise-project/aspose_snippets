```cs

//create empty pdf document
using var doc = new Aspose.Pdf.Document();

//make list of file streams with documents to merge
streams = new List<Stream>(){ File.Open("1.jpg", FileMode.Open), File.Open("1.jpg", FileMode.Open) };

//add new page to pdf
//add image to new pdf page
foreach (var fs in streams)
{
    page = doc.Pages.Add();
    page.AddImage(fs, new Aspose.Pdf.Rectangle(0, 0, 700, 1000));
}

//save result pdf to file
doc.Save("Merger_jpg_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```