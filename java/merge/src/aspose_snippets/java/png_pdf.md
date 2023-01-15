
//1. create empty pdf document
com.aspose.pdf.Document doc = new com.aspose.pdf.Document();

//2. make list of files with images to merge
List<String> images = Arrays.asList(new String[]{"1.png", "2.png"});

//3. add image to new pdf page
//add new page to pdf
for (String fs : images) {
    com.aspose.pdf.Page page = doc.getPages().add();
    page.addImage(fs, new com.aspose.pdf.Rectangle(0, 0, 700, 1000);
}

//4. save result pdf to file
doc.save("Merger_png_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
