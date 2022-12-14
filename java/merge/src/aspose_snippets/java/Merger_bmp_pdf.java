package aspose_snippets.java;

public class Merger_bmp_pdf {
    public static void Execute() {
        var pathSource1 = @"..\..\TestData\test.bmp";
            var pathSource2 = @"..\..\TestData\Second\test.bmp";

            //create empty pdf document
            using var doc = new Aspose.Pdf.Document();

            //make list of file streams with documents to merge
            var streams = new List<Stream>() 
            { 
                File.Open(pathSource1, FileMode.Open), 
                File.Open(pathSource2, FileMode.Open) 
            };

            foreach (var fs in streams)
            {
                //add new page to pdf
                Aspose.Pdf.Page page = doc.Pages.Add();
                
                //setup page size to be A4
                page.SetPageSize(
                    Aspose.Pdf.PageSize.A4.Width, 
                    Aspose.Pdf.PageSize.A4.Height);

                Aspose.Pdf.Rectangle rect;
Ы
                //load image from stream, it suport a lot of formats
                using (Aspose.Imaging.Image image = Aspose.Imaging.Image.Load(fs))
                {
                    //read image dimensions to pdf page rectangle
                    rect = new Aspose.Pdf.Rectangle(0, 0, image.Width - 1, image.Height - 1);
                }

                fs.Seek(0, SeekOrigin.Begin);
            
                page.AddImage(fs, rect);
            }

            doc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
            foreach(var fs in streams)
            {
                fs.Dispose();
            }
    }
}
