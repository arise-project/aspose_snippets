package aspose_snippets.java;

public class Split_PDF {
    public static void Execute() {
        String pathSource = "../../TestData/test.pdf";
        com.aspose.pdf.facades.PdfFileEditor pdfEditor = new com.aspose.pdf.facades.PdfFileEditor();
        int beg = 1, end = 1;
    
        com.aspose.pdf.Document doc = new com.aspose.pdf.Document(pathSource);
        end = doc.getPages().size();
    
        if(end > 1)
        {
            end /= 2;
        }
    
        pdfEditor.extract(pathSource, beg, end, "pdf_half.pdf");
    }
}
