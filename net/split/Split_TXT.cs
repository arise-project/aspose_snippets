using Aspose.Pdf;
using Aspose.Pdf.Facades;
using Aspose.Pdf.Text;

namespace aspose_snippets.net
{
    public static partial class Split
    {
        public static void TXT()
        {
            var pathSource = "../../TestData/test.txt";
            var pdfEditor = new PdfFileEditor();
            
            using (var doc = new Document(pathSource, new TxtLoadOptions()))
            {
                //save input text to pdf to file
                doc.Save("test.pdf", SaveFormat.Pdf);
            }

            MemoryStream [] pages = pdfEditor.SplitToPages("test.pdf");
            int index = 1;
            foreach(var ms in pages)
            {
                using(var page = new Document(ms))
                {
                    var textAbsorber = new TextAbsorber();
                    page.Pages.Accept(textAbsorber);
                    string extractedText = textAbsorber.Text;
                    File.WriteAllText("text_"+index+".txt", extractedText);
                    index++;
                }
            }
            File.Delete("test.pdf");
        }
    }
}
