namespace aspose_snippets.net.merger
{
    /// <summary>
    ///     Provide license for using the Aspose.PDF.dll library.
    /// </summary>
    public static class LicenseProvider
    {
        /// <summary>
        ///     The license path if is a file and located on disk.
        /// </summary>
        public static string LicensePath => "../../test.lic";
        

        /// <summary>
        ///     Get the license stream.
        /// </summary>
        /// <returns>Stream containing license.</returns>
        public static void License()
        {
            using (var fileStream = new FileStream(LicensePath, FileMode.Open, FileAccess.Read))
            {
                using(var memoryStream = new MemoryStream())
                {
                    fileStream.CopyTo(memoryStream);
                    
                    //reset stream to read from begin for next step
                    memoryStream.Seek(0, SeekOrigin.Begin);
                    new Aspose.Pdf.License().SetLicense(memoryStream);
                }
            }
        }
    }
}
