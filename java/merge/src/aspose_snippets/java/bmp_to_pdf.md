```java

//1. create empty pdf document
doc = new com.aspose.pdf.Document();

//2. add new page to pdf
//add image to new pdf page
//make list of files with images to merge
//read image dimensions to pdf page rectangle
List<String> images = Arrays.asList(new String[]{"1.bmp", "2.bmp"});
for (String fs : images) {
    page = doc.getPages().add();
    page.addImage(fs, new com.aspose.pdf.Rectangle(0, 0, 700, 1000));
}

//3. save result pdf to file
doc.save("Merger_bmp_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
```