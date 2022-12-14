using Aspose.Pdf;
using Aspose.Pdf.Text;

namespace aspose_snippets.net
{
    public static partial class Merger
    {
        public static void pdf_to_text()
        {
            var pathSource1 = @"..\..\TestData\test.pdf";
            var pathSource2 = @"..\..\TestData\Second\test.pdf";

            var firstDoc = new Document(pathSource1);
            var secondDoc = new Document(pathSource2);

            var outputDoc = new Document();

            //set less memory usage with unload instead of fast performance
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            var textAbsorber = new TextAbsorber();
            outputDoc.Pages.Accept(textAbsorber);
            string extractedText = textAbsorber.Text;
            File.WriteAllText("test.txt", extractedText);
        }
    }
}
