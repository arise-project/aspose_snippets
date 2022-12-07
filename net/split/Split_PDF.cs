using Aspose.Pdf;
using Aspose.Pdf.Facades;

namespace aspose_snippets.net
{
    public static partial class Split
    {
        public static void PDF()
        {
            var pathSource = @"..\..\TestData\test.pdf";
            var pdfEditor = new PdfFileEditor();
            int beg = 1, end = 1;

            using (var fs = new FileStream(pathSource, FileMode.Open, FileAccess.Read))
            {
                
                using (var doc = new Document(fs))
                {
                    end = doc.Pages.Count;
                }
            }

            if(end > 1)
            {
                    end /= 2;
            }

            pdfEditor.Extract(pathSource, beg, end, "./half.pdf");
        }
    }
}
