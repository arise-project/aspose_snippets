using Aspose.Pdf;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void jpg_to_docx()
        {
            var pathSource1 = @"..\..\TestData\test.jpg";
            var pathSource2 = @"..\..\TestData\Second\test.jpg";

            using var doc = new Document();
            doc.EnableObjectUnload = true;

            Rectangle rect;
            double width, height;

            var streams = new List<Stream>() { File.Open(pathSource1, FileMode.Open), File.Open(pathSource2, FileMode.Open) };

            foreach (var fs in streams)
            {
                Page page = doc.Pages.Add();
                page.SetPageSize(PageSize.A4.Width, PageSize.A4.Height);

                using (Aspose.Imaging.Image image = Aspose.Imaging.Image.Load(fs))
                {
                    rect = new Rectangle(0, 0, image.Width - 1, image.Height - 1);
                    width = image.Width;
                    height = image.Height;
                }

                fs.Seek(0, SeekOrigin.Begin);
            
                page.AddImage(fs, rect);
            }

            doc.Save("test.docx", SaveFormat.DocX);
            foreach(var fs in streams)
            {
                fs.Dispose();
            }
        }
    }
}
