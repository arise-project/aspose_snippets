namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void bmp_to_pdf()
        {
            const string pathSource1 = "../../TestData/test.bmp";
            const string pathSource2 = "../../TestData/Second/test.bmp";

            //create empty pdf document
            using var doc = new Aspose.Pdf.Document();

            Aspose.Pdf.Rectangle rect;

            //make list of file streams with documents to merge with documents to merge
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
            doc.Save("Merger_bmp_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
