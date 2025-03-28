//
// FormattingChannel.h
//
// Library: Foundation
// Package: Logging
// Module:  Formatter
//
// Definition of the FormattingChannel class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_FormattingChannel_INCLUDED
#define Foundation_FormattingChannel_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Channel.h"
#include "Poco/Formatter.h"
#include "Poco/AutoPtr.h"


namespace Poco {


class Formatter;


class Foundation_API FormattingChannel: public Channel
	/// The FormattingChannel is a filter channel that routes
	/// a Message through a Formatter before passing it on
	/// to the destination channel.
{
public:
	using Ptr = AutoPtr<FormattingChannel>;

	FormattingChannel();
		/// Creates a FormattingChannel.

	FormattingChannel(Formatter::Ptr pFormatter);
		/// Creates a FormattingChannel and attaches a Formatter.

	FormattingChannel(Formatter::Ptr pFormatter, Channel::Ptr pChannel);
		/// Creates a FormattingChannel and attaches a Formatter
		/// and a Channel.

	void setFormatter(Formatter::Ptr pFormatter);
		/// Sets the Formatter used to format the messages
		/// before they are passed on. If null, the message
		/// is passed on unmodified.

	Formatter::Ptr getFormatter() const;
		/// Returns the Formatter used to format messages,
		/// which may be null.

	void setChannel(Channel::Ptr pChannel);
		/// Sets the destination channel to which the formatted
		/// messages are passed on.

	Channel::Ptr getChannel() const;
		/// Returns the channel to which the formatted
		/// messages are passed on.

	void log(const Message &msg) override;
		/// Formats the given Message using the Formatter and
		/// passes the formatted message on to the destination
		/// Channel.

	void setProperty(const std::string& name, const std::string& value) override;
		/// Sets or changes a configuration property.
		///
		/// Only the "channel" and "formatter" properties are supported, which allow
		/// setting the target channel and formatter, respectively, via the LoggingRegistry.
		/// The "channel" and "formatter" properties are set-only.
		///
		/// Unsupported properties are passed to the attached Channel.

	void open() override;
		/// Opens the attached channel.

	void close() override;
		/// Closes the attached channel.

protected:
	~FormattingChannel() override;

private:
	Formatter::Ptr _pFormatter;
	Channel::Ptr   _pChannel;
};


} // namespace Poco


#endif // Foundation_FormattingChannel_INCLUDED
