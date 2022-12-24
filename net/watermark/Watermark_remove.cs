namespace aspose_snippets.net
{
    public static partial class Watermark
    {
        public static void remove()
        {
            const string pathSource = "../../TestData/test_with_watermark.pdf";
            var doc = new Aspose.Pdf.Document(pathSource);

            if(doc.Pages[1].Artifacts[1].Subtype == Aspose.Pdf.Artifact.ArtifactSubtype.Watermark)
            {
                doc.Pages[1].Artifacts.Delete(doc.Pages[1].Artifacts[1]);
            }

            //save result pdf to file
            doc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
        }
    }
}
