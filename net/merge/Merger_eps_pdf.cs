using Aspose.Pdf;

namespace aspose_snippets.net
{
	public static partial class Merger
	{
        public static void eps_to_pdf()
        {
            var pathSource1 = @"..\..\TestData\test.eps";
            var pathSource2 = @"..\..\TestData\Second\test.eps";

            var firstDoc = new Document(pathSource1, new PsLoadOptions());
            var secondDoc = new Document(pathSource2,  new PsLoadOptions());

            var outputDoc = new Document();
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                outputDoc.Pages.Add(page);
            }

            outputDoc.Save("test.pdf", SaveFormat.Pdf);
        }
	}	
}
