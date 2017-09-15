/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (c) 2012 Vmware, Inc.  All rights reserved.
 *  -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#ifndef SchemaSummaryXml_h_
#define SchemaSummaryXml_h_


#include "Doc/ProviderInfraDoc/CSchemaSummaryDoc.h"

#include "Doc/DocXml/ProviderInfraXml/ProviderInfraXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the SchemaSummary class to/from XML
	namespace SchemaSummaryXml {

		/// Adds the SchemaSummaryDoc into the XML.
		void PROVIDERINFRAXML_LINKAGE add(
			const SmartPtrCSchemaSummaryDoc schemaSummaryDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the SchemaSummaryDoc from the XML.
		SmartPtrCSchemaSummaryDoc PROVIDERINFRAXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif