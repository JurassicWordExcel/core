/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */
#ifndef INCLUDED_FORMS_SOURCE_XFORMS_XFORMSEVENT_HXX
#define INCLUDED_FORMS_SOURCE_XFORMS_XFORMSEVENT_HXX

#include <sal/types.h>
#include <cppuhelper/implbase.hxx>
#include <com/sun/star/uno/Reference.h>
#include <com/sun/star/xforms/XFormsEvent.hpp>
#include <com/sun/star/xml/dom/events/XEventTarget.hpp>

namespace com {
namespace sun {
namespace star {
namespace xforms {

class XFormsEventConcrete : public cppu::WeakImplHelper< XFormsEvent > {

    public:

        XFormsEventConcrete()
            : m_canceled(false)
            , m_phase(com::sun::star::xml::dom::events::PhaseType_CAPTURING_PHASE)
            , m_bubbles(false)
            , m_cancelable(false)
        {
        }
        virtual ~XFormsEventConcrete() {}

        virtual OUString SAL_CALL getType() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual css::uno::Reference< css::xml::dom::events::XEventTarget > SAL_CALL getTarget() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual css::uno::Reference< css::xml::dom::events::XEventTarget > SAL_CALL getCurrentTarget() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual css::xml::dom::events::PhaseType SAL_CALL getEventPhase() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual sal_Bool SAL_CALL getBubbles() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual sal_Bool SAL_CALL getCancelable() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual css::util::Time SAL_CALL getTimeStamp() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual void SAL_CALL stopPropagation() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;
        virtual void SAL_CALL preventDefault() throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;

        virtual void SAL_CALL initXFormsEvent(
                            const OUString& typeArg,
                            sal_Bool canBubbleArg,
                            sal_Bool cancelableArg )
                            throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;

        virtual void SAL_CALL initEvent(
            const OUString& eventTypeArg,
            sal_Bool canBubbleArg,
            sal_Bool cancelableArg)
            throw (css::uno::RuntimeException, std::exception) SAL_OVERRIDE;

    private:

        bool m_canceled;

    protected:

        OUString m_eventType;
        css::uno::Reference< css::xml::dom::events::XEventTarget > m_target;
        css::uno::Reference< css::xml::dom::events::XEventTarget > m_currentTarget;
        css::xml::dom::events::PhaseType m_phase;
        bool m_bubbles;
        bool m_cancelable;
        css::util::Time m_time;
};

} } } }

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
