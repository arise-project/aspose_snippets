package aspose_snippets.java;

public class Split_PDF {
    public static void Execute() {
const string pathSource = "../../TestData/test.pdf";
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
