
//1. create empty pdf document
doc = new Aspose.Pdf.Document();

//2. make list of file streams with documents to merge
streams = new List<Stream>(){ File.Open("1.pmg", FileMode.Open), File.Open("2.pmg", FileMode.Open) };

//3. add new page to pdf
//add image to new pdf page
foreach (var fs in streams)
{
    page = doc.Pages.Add();
    page.AddImage(fs, new Aspose.Pdf.Rectangle(0, 0, 700, 1000));
}

//4. save result pdf to file
doc.Save("Merger_png_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
