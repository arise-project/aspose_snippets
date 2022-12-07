using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;

namespace Aspose.PDF.Shared.Helpers
{
    /// <summary>
    ///     Provide license for using the Aspose.PDF.dll library.
    /// </summary>
    public static class LicenseProvider
    {
        #region _fields_

        /// <summary>
        ///     Sync object
        /// </summary>
        private static readonly object SyncObject = new object();

        /// <summary>
        ///     License Embedded Resource path.
        /// </summary>
        private const string LicenseResource = "Aspose.PDF.NATS.Common.AppResources.Aspose.Total.lic";

        #endregion

        #region _properties_

        /// <summary>
        ///     The license path if is a file and located on disk.
        /// </summary>
        public static string LicensePath { get; set; }

        #endregion

        #region Methods

        /// <summary>
        ///     Get the license stream.
        /// </summary>
        /// <returns>Stream containing license.</returns>
        public static Stream LicenseStream()
        {
            lock (SyncObject)
            {
                if (string.IsNullOrEmpty(LicensePath))
                {
                    var stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(LicenseResource);
                    return stream;
                }

                using (var fileStream = new FileStream(LicensePath, FileMode.Open, FileAccess.Read))
                {
                    var memoryStream = new MemoryStream();
                    fileStream.CopyTo(memoryStream);
                    memoryStream.Seek(0, SeekOrigin.Begin);
                    return memoryStream;
                }
            }
        }

        #endregion
    }
}
