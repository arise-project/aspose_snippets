
//create empty pdf document
doc = new Aspose.Pdf.Document();

//make list of file streams with documents to merge
streams = new List<Stream>() { File.Open("1.jpg", FileMode.Open), File.Open("2.jpg", FileMode.Open) };

//add new page to pdf
//add image to new pdf page
foreach (var fs in streams)
{
    page = doc.Pages.Add();
    page.AddImage(fs, new Aspose.Pdf.Rectangle(0, 0, 700, 1000));
}

doc.Save("Merger_jpg_docx.docx", Aspose.Pdf.SaveFormat.DocX);
