/*
 *	 Author: bwilliams
 *  Created: Oct 22, 2010
 *
 *	Copyright (c) 2010 Vmware, Inc.  All rights reserved.
 *	-- VMware Confidential
 */

#ifndef _IntegrationContracts_ITransformer_h_
#define _IntegrationContracts_ITransformer_h_

namespace Caf {

/// TODO - describe interface
struct __declspec(novtable)
	ITransformer : public ICafObject
{
	CAF_DECL_UUID("1f2a6ecb-f842-4e09-82a8-89eaf64ec98b")

	virtual SmartPtrIIntMessage transformMessage(
		const SmartPtrIIntMessage& message) = 0;
};

CAF_DECLARE_SMART_INTERFACE_POINTER(ITransformer);

}

#endif // #ifndef _IntegrationContracts_ITransformer_h_
