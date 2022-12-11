namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void jpg_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.jpg";
            var pathSource2 = @"..\..\TestData\Second\test.jpg";

            using var doc = new Aspose.Pdf.Document();
            doc.EnableObjectUnload = true;

            Aspose.Pdf.Rectangle rect;
            double width, height;

            var streams = new List<Stream>() { File.Open(pathSource1, FileMode.Open), File.Open(pathSource2, FileMode.Open) };

            foreach (var fs in streams)
            {
                Aspose.Pdf.Page page = doc.Pages.Add();
                page.SetPageSize(Aspose.Pdf.PageSize.A4.Width, Aspose.Pdf.PageSize.A4.Height);

                using (Aspose.Imaging.Image image = Aspose.Imaging.Image.Load(fs))
                {
                    rect = new Aspose.Pdf.Rectangle(0, 0, image.Width - 1, image.Height - 1);
                    width = image.Width;
                    height = image.Height;
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
}
