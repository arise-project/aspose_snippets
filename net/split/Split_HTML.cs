using Aspose.Pdf.Facades;

namespace aspose_snippets.net
{
    public static partial class Split
    {
        public static void HTML()
        {
            var pathSource = @"..\..\test.html";
            var pdfEditor = new PdfFileEditor();
            pdfEditor.SplitFromFirst(pathSource, 1, "./first.html");
        }
    }
}
