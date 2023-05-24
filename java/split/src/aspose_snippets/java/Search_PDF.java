

public class Split_PDF {
    public static void Execute() {
        String pathSource = "../../TestData/test.pdf";
        com.aspose.pdf.Document doc = new com.aspose.pdf.Document(pathSource);
        com.aspose.pdf.TextFragmentAbsorber fa =  new com.aspose.pdf.TextFragmentAbsorber("demo");
        doc.getPages().accept(fa);
        com.aspose.pdf.TextFragmentCollection tc = fa.getTextFragments();
        for(com.aspose.pdf.TextFragment f : (Iterable<com.aspose.pdf.TextFragment>)tc){
            f.setText("release");
            f.getTextState().setFont(com.aspose.pdf.FontRepository.findFont("Verdana", 0, false));
            f.getTextState().setFontSize(12);
            f.getTextState().setForegroundColor(com.aspose.pdf.Color.getBeige());
        }
        doc.save("updated.pdf");
    }
}
