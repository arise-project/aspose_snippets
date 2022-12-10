using Aspose.Pdf;
using Aspose.Pdf.Annotations;

namespace aspose_snippets.net
{
    public static partial class Watermark
    {
        public static void get()
        {
            var pathSource = @"..\..\TestData\test_with_watermark.pdf";
            var doc = new Aspose.Pdf.Document(pathSource);

            using(var fs = new FileStream("test.jpg",FileMode.Create))
            {
                doc.Pages[1].Artifacts[1].Image.Save(fs);
                fs.Flush();
            }
        }
    }
}
