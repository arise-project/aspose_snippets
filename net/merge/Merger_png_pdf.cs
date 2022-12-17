namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void png_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.png";
            var pathSource2 = @"..\..\TestData\Second\test.png";

            //create empty pdf document    
            using var doc = new Aspose.Pdf.Document();

            //set less memory usage with unload instead of fast performance
            doc.EnableObjectUnload = true;

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
                //load image from stream, it supports a lot of formats
                using (Aspose.Imaging.Image image = Aspose.Imaging.Image.Load(fs))
                {
                    //read image dimensions to pdf page rectangle
                    rect = new Aspose.Pdf.Rectangle(0, 0, image.Width - 1, image.Height - 1);
                }
                
                //reset stream to read from begin for next step
                fs.Seek(0, SeekOrigin.Begin);

                //add image to new pdf page
                page.AddImage(fs, rect);
            }

            //save result pdf to file
            doc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
